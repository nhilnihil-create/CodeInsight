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
typedef long long i64;
typedef vector<i64> vi64;
typedef vector<vi64> vvi64;
typedef pair<i64, i64> pi64;
typedef double ld;


int main(){
        
    ios_base::sync_with_stdio(0);
    
    //ofstream fout ("test.out");
    //ifstream fin ("test.in");
    //fin >> a >> b;
    //fout << a+b << endl;
    string s;
    cin>>s;
    int n = s.length();
    
    if(s[0]!='A'){
        cout<<"WA\n";
        return 0;
    }
    
    //cnt_C = 0;
    bool flag = false;
    for(int i=1;i<n;i++){
        if(i>=2 && i<=n-2){
            if(s[i]=='C'){
                if(!flag)   flag=true;
                else{
                    cout<<"WA\n";
                    return 0;
                }
            }
            else if(s[i]>=65 && s[i]<=90){
                cout<<"WA\n";
                return 0;
            }
        }

            else if(s[i]>=65 && s[i]<=90){
                cout<<"WA\n";
                return 0;
            }

    }
    if(!flag)   cout<<"WA\n";
    else        cout<<"AC\n";
    return 0;
}

