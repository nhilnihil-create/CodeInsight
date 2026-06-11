#include <algorithm>
#include <complex>
#include <cstdlib>
#include <ctime>
#include <time.h>
#include <iomanip>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <random>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <vector>

using namespace std;
#define SAY_YES cout << "YES" << endl;
#define SAY_Yes cout << "Yes" << endl;
#define SAY_NO cout << "NO" << endl;
#define SAY_No cout << "No" << endl;
#define IFYES(TRUE_OR_FALSE)   \
    if (TRUE_OR_FALSE)         \
    {                          \
        cout << "YES" << endl; \
    }                          \
    else                       \
    {                          \
        cout << "NO" << endl;  \
    }
#define IFYes(TRUE_OR_FALSE)   \
    if (TRUE_OR_FALSE)         \
    {                          \
        cout << "Yes" << endl; \
    }                          \
    else                       \
    {                          \
        cout << "No" << endl;  \
    }
#define IFyes(TRUE_OR_FALSE)   \
    if (TRUE_OR_FALSE)         \
    {                          \
        cout << "yes" << endl; \
    }                          \
    else                       \
    {                          \
        cout << "no" << endl;  \
    }
#define DEBUG_OUTPUT_ARRAY(XXX, ONE)                            \
    for (int i = 0; i < (ONE); i++)                             \
    {                                                           \
        cout << "DEBUG: i = " << i << " -> " << XXX[i] << endl; \
    }
#define DEBUG_OUTPUT_ARRAY2(XXX, ONE, TWO)                             \
    for (int i = 0; i < (ONE); i++)                                    \
    {                                                                  \
        cout << "<<< i = " << i << " >>>" << endl;                     \
        for (int j = 0; j < (TWO); j++)                                \
        {                                                              \
            cout << "DEBUG: j = " << j << " -> " << XXX[i][j] << endl; \
        }                                                              \
    }
#define DEBUG_OUTPUT_ARRAY2_BOX(XXX, ONE, TWO) \
    for (int i = 0; i < (ONE); i++)            \
    {                                          \
        cout << i << "  ";                     \
        for (int j = 0; j < (TWO); j++)        \
        {                                      \
            cout << XXX[i][j] << " ";          \
        }                                      \
        cout << endl;                          \
    }

typedef pair<long long int, long long int> pll;


const long long int mod = 998244353;
const long long int INF = 1e18;




long long int H,N,W,A[105000],B,K,sum[5000]={};

char ch;
string s;
stack<char>st;
vector<long long int>vec,ok,ng;
int main()
{
    cout << fixed << setprecision(18);
    cin>>N>>K;
    
    for(long long int i = 1; i <= N; i++){
        cin>>A[i];
    }
    for(long long int i = 1; i <= N; i++){
        sum[i]=sum[i-1]+A[i];
    }
    //cout<<"x";
    for(long long int i = 1; i <= N; i++){
        for(long long int j = i; j <= N; j++){
            vec.push_back(sum[j]-sum[i-1]);
        }
        
    }
    //cout<<"x";
    sort(vec.begin(),vec.end());
    long long int tmp=0;
    for(long long int  i= 0;  (1LL<<i)<vec[vec.size()-1] ; i++){
        //cout<<"a";
        tmp=(1LL<<i);
    }
    
    long long int now=0;
    while(tmp!=0){
        
        ok.clear();
            
        for(long long int i = 0; i < vec.size(); i++){
            if((vec[i]&tmp)!=0){
                ok.push_back(vec[i]);
            }else{
                
            }
        }
        if(ok.size()<K){

        }else{
            vec=ok;
            now+=tmp;
            //DEBUG_OUTPUT_ARRAY(ok,ok.size());
        }
        tmp/=2;
    }
    cout<<now<<endl;
}
