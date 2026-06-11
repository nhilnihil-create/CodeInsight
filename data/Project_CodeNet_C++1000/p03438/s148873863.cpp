#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

const int INF=1e9;
const int MOD=1e9+7;

int main(){
    int N; cin >> N;
    int a[N],b[N];
    for(int i=0;i<N;i++){
        cin >> a[i];
    }
    for(int i=0;i<N;i++){
        cin >> b[i];
    }
    ll sa=0; ll sb=0;
    for(int i=0;i<N;i++){
        if(a[i]<b[i]) sb+=(b[i]-a[i])/2;
        if(a[i]>b[i]) sa+=a[i]-b[i];
    }
    if(sb>=sa){
        cout << "Yes" << endl;
    }else{
        cout << "No" << endl;
    }
}
    
