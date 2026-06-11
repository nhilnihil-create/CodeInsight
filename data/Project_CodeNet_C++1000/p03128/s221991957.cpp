#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i,n,k) for(int i=(n);i<(k);i++)
#define ALL(a)  (a).begin(),(a).end()
int cost[10]={-1,2,5,5,4,5,6,3,7,6};
vector<pair<int,string>> ers(vector<pair<int,string>> &vec){
    vector<pair<int,string>> ret;
    sort(ALL(vec));
    For(i,0,vec.size()){
        if(i==vec.size()-1 || vec[i].first<vec[i+1].first) ret.push_back(vec[i]);
    }
    sort(ALL(ret),[](auto l,auto r){return l.second>r.second;});
    return ret;
}
string comp(string a,string b){
    string s;
    if(a.size()>b.size()) s=a;
    else if(a.size()<b.size()) s=b;
    else if(a>b) s=a;
    else s=b;
    return s;
}
void Main(){
    int n,m;
    cin >> n >> m;
    vector<pair<int,string>> vec;
    For(i,0,m){
        int a;
        cin >> a;
        string s="";
        s.push_back(char(a+'0'));
        vec.push_back({cost[a],s});
    }
    vec=ers(vec);
    m=vec.size();
    vector<vector<string>> dp(m+1,vector<string> (n+1,""));
    For(i,0,m){
        For(j,1,n+1){
            dp[i+1][j]=dp[i][j];
            if(j==vec[i].first) dp[i+1][j]=comp(dp[i+1][j],vec[i].second);
            if(j>vec[i].first && dp[i+1][j-vec[i].first]!=""){
                char c=vec[i].second[0];
                string s=dp[i+1][j-vec[i].first];
                s.push_back(c);
                dp[i+1][j]=comp(dp[i+1][j],s);
            }
        }
    }
    cout<<dp[m][n]<<endl;
}
int main(){
    Main();
    /*
    東方風神録は神が出てくるので当然神ゲー
    */
    return 0;
}