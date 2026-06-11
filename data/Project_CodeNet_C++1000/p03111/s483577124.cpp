#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll N,A,B,C;
vector<ll> l;
ll ans = 100100100ll;

void dfs(int t, vector<int> &AL, vector<int> &BL,vector<int> &CL){
    if(t==N){
        //評価
        if(AL.size() ==0 || BL.size()==0||CL.size()==0){
            return;
        }
        ll sum=0;
        ll temp =0;
        for(ll a:AL){
            temp+=a;
        }
        // cerr << "AL" << AL.size()<<"temp="<<temp << endl;
        sum += (abs(temp-A)+(AL.size()-1)*10);
        temp =0;
        for(ll b:BL){
            temp +=b;
        }
        // cerr << "BL" << BL.size()<<"temp="<<temp << endl;
        sum += (abs(temp-B)+(BL.size()-1)*10);
        temp =0;
        for(ll c:CL){
            temp +=c;
        }
        // cerr << "CL" << CL.size()<<"temp="<<temp << endl;
        sum += (abs(temp-C)+(CL.size()-1)*10);
        // cerr << sum << endl;
        ans = min(ans,sum);
        return;
    }
    dfs(t+1,AL,BL,CL);
    
    AL.push_back(l[t]);
    dfs(t+1,AL,BL,CL);
    AL.pop_back();
    
    BL.push_back(l[t]);
    dfs(t+1,AL,BL,CL);
    BL.pop_back();
    
    CL.push_back(l[t]);
    dfs(t+1,AL,BL,CL);
    CL.pop_back();
}

int main() {
    cin >> N >>A >>B >>C;
    l.resize(N);
    for(int i=0;i<N;i++){
        cin >> l[i];
    }
    vector<int> a,b,c;
    dfs(0,a,b,c);
    cout << ans << endl;
    return 0;
}