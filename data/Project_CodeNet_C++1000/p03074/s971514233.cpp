#include<bits/stdc++.h>
#define rp(i,n) for(int i=0; i<n; i++)
using namespace std;
using ll=long long;
using P=pair<int,int>;

int main() {
    int n,k;
    cin >> n >> k;
    string s;
    cin >> s;
    deque<int> seq;
    int ctr=1;
    rp(i,n-1){
        if(s.at(i)==s.at(i+1)) ctr++;
        else{
            seq.push_back(ctr);
            ctr=1;
        }
    }
    seq.push_back(ctr);
    if(s.at(0)=='0') seq.push_front(0);
    if(s.at(n-1)=='0') seq.push_back(0);
    int si=seq.size();
    if(si<=k+k+1){
        cout<< n << endl;
        return 0;
    }
    vector<int> sum(si+1);
    sum.at(0)=0;
    for(int i=1; i<=si; i++){
        sum.at(i)=sum.at(i-1)+seq.at(i-1);
    }
    //for(auto p:sum) cout << p << endl;
    int ans=0;
    for(int i=0; i<=si-k-k-1; i+=2){
        ans=max(ans,sum.at(i+k+k+1)-sum.at(i));
    }
    cout << ans << endl;
    return 0;
}