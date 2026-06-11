#include<bits/stdc++.h>
using namespace std;

vector < int > v[502];

int cal( int a, int b){

    int sum=0,i,x,y;
    for(i=a; i<=b; i++){
        x=lower_bound(v[i].begin(),v[i].end(),a)-v[i].begin();
        y=upper_bound(v[i].begin(),v[i].end(),b)-v[i].begin();
        sum+=(y-x);
    }
    return sum;
}

int main(){

    int a,b, n, m, q, i,j,sum;
    cin>>n>>m>>q;
    for(i=1; i<=m; i++){
        cin>>a>>b;
        v[a].push_back(b);
    }
    for(i=1; i<=n; i++)
        sort(v[i].begin(),v[i].end());
    while(q--){
        cin>>a>>b;
        sum=cal(a,b);
        cout<<sum<<endl;
    }

    return 0;
}