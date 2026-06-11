#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define For(i,n,k) for(int i=(n);i<(k);i++)
#define ALL(a)  (a).begin(),(a).end()
vector<int> match = {-1,2,5,5,4,5,6,3,7,6};
void Main(){
    int n,m;
    cin >> n >> m;
    vector<pair<int,int>> approval(m);//first:本数　second:数
    For(i,0,m) {
        cin >> approval[i].second;
        approval[i].first = match[approval[i].second];
    }
    sort(ALL(approval), [](auto const& l, auto const& r) {//本数は少なく、数は大きくしたい
       if(l.first!=r.first) return l.first < r.first;
       else return l.second > r.second;
    });
    for (int i=1;i<approval.size();) {
    // 本数が同じ要素を削除する
        if (approval[i].first == approval[i-1].first) {
            approval.erase(approval.begin()+i);
        }
        else {
            i++;
        }
    }
    sort(ALL(approval), [](auto const& l, auto const& r) {//数の大きい順に再ソート
       if(l.second != r.second) return l.second > r.second;
       else return l.first > r.first;
    });
    m = approval.size();
    vector<vector<string>> dp(m+1,vector<string> (n+1));
    For(j,0,n+1) dp[0][j]="";
    For(i,0,m+1) dp[i][0]="";
    For(i,0,m){
        For(j,1,n+1){
            if(j<approval[i].first) dp[i+1][j]=dp[i][j];
            else{
                string str1 = dp[i][j];
                string str2 = dp[i+1][j-approval[i].first];
                if(str2 == "" && j != approval[i].first) dp[i+1][j]=str1;
                else{
                    str2.push_back(char(approval[i].second + '0'));
                    if(str1.size()>str2.size()) dp[i+1][j]=str1;
                    else if(str1.size()<str2.size()) dp[i+1][j]=str2;
                    else if(str1>str2) dp[i+1][j]=str1;
                    else dp[i+1][j]=str2;
                }
            }
        }
    }
    cout << dp[m][n] << endl;
}
int main(){
    Main();
    /*
    東方風神録は神が出てくるので当然神ゲー
    */
    return 0;
}