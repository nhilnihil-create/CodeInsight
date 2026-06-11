#include<bits/stdc++.h>
#define ll long long
using namespace std;

ll n,A[200001],B[200001],C[200001],tree[10000001],pos,R,rao,ans;

void upd(int node,int tl,int tr){

    if(tl==tr){
        tree[node] ++;
        return ;
    }
    int mid = (tl+tr-1)/2;
    if(pos<=mid)
        upd(node*2,tl,mid);
    else
        upd(node*2+1,mid+1,tr);

    tree[node] = tree[node*2] + tree[node*2+1];
}

ll get(int node,int tl,int tr){

    if(tl>R)return 0;

    if(tr<=R)return tree[node];

    int mid = (tl+tr-1)/2;
    ll x = get(node*2,tl,mid);
    ll y = get(node*2+1,mid+1,tr);

    return x + y;
}


bool check(int x){

    rao = pos = 0 ;
        //cout<<x<<endl;
    for(int i=1;i<=8*n;i++)
        tree[i] = 0;

    for(int i=1;i<=n;i++){
        if(A[i]>=x)
            C[i] = 1;
        else
            C[i] = -1;
    }

    pos = 0;
    upd(1,-n,n);

    for(int i=1;i<=n;i++){

        pos += C[i];

        R = pos;
        rao += get(1,-n,n);
        //cout<<rao<<"-----"<<pos<<endl;

        if(rao >= (n*(n+1)/2+1)/2 )return true;

        upd(1,-n,n);
    }

    return false;

}

int main(){

    cin>>n;

    for(int i=1;i<=n;i++){
        cin>>A[i];
        B[i] = A[i];
    }

    sort(B+1,B+n+1);

    int l = 1 , r = n;

    while(l<=r){

        int mid = (l+r)/2;

        if(check(B[mid])){
            l = mid+1;
            ans = mid;
        } else {
            r = mid-1;
        }

    }

    cout<<B[ans]<<endl;
}
