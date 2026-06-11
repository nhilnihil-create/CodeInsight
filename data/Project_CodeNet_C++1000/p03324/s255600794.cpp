#include <bits/stdc++.h>
#define rep(i,s,n) for(int i=s;i<n;i++)
#define pb push_back
#define mp make_pair
#define all(x) (x).begin(),(x).end()
#define all_acc(x) (x).begin(),(x).end(),0LL
#define int long long
using namespace std;
using P=pair<int,int>;
using Graph=vector<vector<int>>;
using ll=long long;

int accumulate(int* a,int n){
    return accumulate(a,a+n,0LL);
}

int accumulate(vector<int> a){
    return accumulate(a.begin(),a.end(),0LL);
}

signed main(){ 
    int d,n; cin>>d>>n;




    string s="";
    
    if(n==100){
        s+=to_string(n+1);
    }else{
        s+=to_string(n);
    }

    for(int i=0;i<d;i++){
        s+="00";
    }
    cout<<s<<endl;
}  