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
    int n;
    cin>>n;
    vector<int> dp(3,0),ndp(3);
    vector<int> v(3);
    for(int i=0;i<n;i++){
        for(int i=0;i<3;i++)
            cin>>v[i];
        ndp[0]=max(dp[1],dp[2])+v[0];
        ndp[1]=max(dp[0],dp[2])+v[1];
        ndp[2]=max(dp[1],dp[0])+v[2];
        dp=ndp;
    }

    cout<<*max_element(dp.begin(),dp.end());
    return 0;
}
