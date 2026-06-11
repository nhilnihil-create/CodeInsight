#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;

ll N;

void search(ll n, vi &candidate){
    //cout << n << endl;
    for(int i=3;i<=7;i+=2){
        ll ret=n*10+i;
        if(ret<=N){
            candidate.push_back(ret);
            search(ret,candidate);
        }
    }
    return;
}

int main(){
    cin >> N;
    vi candidate;
    search(0,candidate);
    //cout << "kani" << endl;
    int ans=0;
    for(int x:candidate){
        //cout << x << endl;
        bool flag3=false,flag5=false,flag7=false;
        while(x>0){
            if((x%10)%3==0) flag3=true;
            if((x%10)%5==0) flag5=true;
            if((x%10)%7==0) flag7=true;
            x/=10;
        }   
        if(flag3&flag5&flag7) ans++;
    }
    cout << ans << endl;
    
}