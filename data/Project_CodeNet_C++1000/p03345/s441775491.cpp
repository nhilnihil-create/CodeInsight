/*
ID: learnin7
TASK: test
LANG: C++                 
*/
/* LANG can be C++11 or C++14 for those more recent releases */
#include<bits/stdc++.h>

/*  Macros from Endagorion */
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define pb push_back
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
#define for1(i, n) for (int i = 1; i <= (int)(n); ++i)
#define ford(i, n) for (int i = (int)(n) - 1; i >= 0; --i)
#define fore(i, a, b) for (int i = (int)(a); i <= (int)(b); ++i)

using namespace std;

typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpi;
typedef vector<vi> vvi;
typedef long long int i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;


/*
 *  a,b,c
 *  1 --> b+c, a+c, b+a; ---> x = b+c - a-c = b-a;
 *  2 --> 2a+b+c, 2b +c+a, ... ---> x = 2a+b+c -2b-c-a = a-b;  
 */
int main(){
        
    ios_base::sync_with_stdio(0);
    
    //ofstream fout ("test.out");
    //ifstream fin ("test.in");
    //fin >> a >> b;
    //fout << a+b << endl;
    i64 a,b,c;
    i64 k;
    cin>>a>>b>>c>>k;
    if(k%2==1) cout<<b-a<<endl;
    else       cout<<a-b<<endl;
    return 0;
}

