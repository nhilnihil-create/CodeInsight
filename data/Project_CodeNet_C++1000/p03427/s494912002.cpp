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


int sum_dig(i64 num){
    int sum =0;
    while(num){
        sum += (num%10);
        num /= 10;
    }

    return sum;
}
int main(){
        
    ios_base::sync_with_stdio(0);
    
    //ofstream fout ("test.out");
    //ifstream fin ("test.in");
    //fin >> a >> b;
    //fout << a+b << endl;
    i64 n;
    cin>>n;
    //i64 x;
    
    int num_digits = int(log10(n))+1;
    

    int max_sum=sum_dig(n);
    
    i64 expo = i64(pow(10,num_digits-1));
    i64 p = ((n/expo)*expo) - 1;

    max_sum = max(max_sum, sum_dig(p));


    /*
    for(i64 i=1;i<=n;i++){
        int sum = 0;
        i64 num=i;
        while(num){
            sum += (num%10);
            num /= 10;
        }
        if(sum>max_sum){
            max_sum = sum;
            x = i;
        }
       // max_sum = max(sum, max_sum);
    }*/
    cout<<max_sum<<endl;
    return 0;
}

