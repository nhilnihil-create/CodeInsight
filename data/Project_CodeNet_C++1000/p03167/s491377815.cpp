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





int MOD=1e9+7;

int main() {
    int h,w;
    cin>>h>>w;

    vector<vector<char>> mat(h,vector<char> (w));
    vector<vector<long long>> dp(h,vector<long long> (w)); 

    for(int i=0;i<h;i++)
        for(int j=0;j<w;j++)
            cin>>mat[i][j];
            

    dp[0][0]=1;
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            for(int r:{i,i+1}){
                int c=j;
                if(r==i)
                    c++;
                if(r<h && c<w && mat[r][c]=='.'){
                    dp[r][c]+=dp[i][j];
                    dp[r][c]%=MOD;
                }
            }
  
        }

    }

  	

    cout<<dp[h-1][w-1];

    return 0;
}
