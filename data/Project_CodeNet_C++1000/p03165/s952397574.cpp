//codeforces
#include <algorithm>
#include <vector>
#include <string>
#include <ctype.h>
#include <set>
#include <map>
#include<cstdio>
#include<queue>
#include<cstdlib>
#include<time.h>
#include<string>
#include<stack>
#include<cmath>
#include<iostream>
#include<cstring>
#include<complex>
#include<bitset>
#include <climits>
#include<tr1/unordered_set>
#include<tr1/unordered_map>


#define FOR(i,j,k) for(int i=j;i<k;i++)
#define FORD(i,j,k) for(int i=j;i>=k;i--)
#define ll long long
//Make sure no overflow problems
//#define int long long
#define pii  pair<int, int>
#define vi vector<int >
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define VAR(i,n) __typeof(n) i = (n)
#define FOREACH(i,c) for(VAR(i,(c).begin());i!=(c).end();i++)
#define FORDEACH(i,c) for( VAR(i,(c).rbegin()),i!=(c).rend();i++)
#define REP(i,n) FOR(i,0,n)
#define ld long double
const int INF = 1e9+7;
const long long INFLL = (ll)INF * (ll)INF;
const ld EPS = 10e-9;

using namespace std;

class TrieNode{
    public:
    bool isword;
    char c;
    map<char,TrieNode*> m;
    string word;
    public:
    TrieNode(){}
    TrieNode(char ch){
        c=ch;
        isword=false;
    }
};

void insert(TrieNode* root,string word){
    TrieNode* temp=root;
    for(char c:word){
        if(temp->m.find(c)==temp->m.end())
            temp->m[c]=new TrieNode(c);
        temp=temp->m[c];
    }
    temp->isword=true;
    temp->word=word;
}

#pragma GCC optimize ("Ofast")
static auto _ = [] { std::ios::sync_with_stdio(0); std::cin.tie(0); std::cout.tie(0); std::cerr.tie(0); return 0; } ();

int main() {
    string s,t;
  	cin>>s;
  	cin>>t;
    int n=s.size(),m=t.size();
    vector<vector<int>> dp(n+1,vector<int> (m+1));

    string ans="";

    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0 || j==0)
                dp[i][j]=0;
            else if(s[i-1]==t[j-1]){
                dp[i][j]=dp[i-1][j-1]+1;
            }
            else if(s[i-1]!=t[j-1])
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }
  
  	
    int i=n,j=m;
    while(i>0 && j>0){
        if(s[i-1]==t[j-1]){
            i--,j--;
            ans+=s[i];
        }
        else if(dp[i][j-1]<dp[i-1][j]){
            i--;
        }
        else
            j--;
    }

    reverse(ans.begin(),ans.end());

    cout<<ans;
    return 0;
}
