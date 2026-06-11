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
#include <numeric>
#include <limits>
#include <type_traits>


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


const long long int mod = 1000000007;
const long long int INF = 1e18;
const long double PI=3.14159265358979323; 

long long int N,M,A[20]={},B,c[200],res=0,Match[20]={0,2,5,5,4,5,6,3,7,6};
string S[300];
map<string,long long int>mp;
long long int dp[10005][12]={};

int main()
{
    cout << fixed << setprecision(18);
    cin>>N>>M;
    for(long long int i = 0; i < M; i++){
        cin>>A[i];
    }
    for(long long int i = 0; i < N; i++){
        for(long long int j = 0; j < 10; j++){
            dp[i][j]=-INF/10;
        }
    }
  	
    for(long long int i = N; i >=1; i--){
      	
        for(long long int j = 0; j < M; j++){
          
            if(i<Match[A[j]]){continue;}
            bool ok=false;
            
            if(dp[i-Match[A[j]]][0]<dp[i][0]+1){ok=true;}
            for(long long int k = 9; k >=1; k--){
                if(A[j]==k){
                    if(dp[i-Match[A[j]]][k]<dp[i][k]+1){ok=true;break;}
                    else if(dp[i-Match[A[j]]][k]>dp[i][k]+1){break;}
                }else{

                    if(dp[i-Match[A[j]]][k]<dp[i][k]){ok=true;break;}
                    else if(dp[i-Match[A[j]]][k]>dp[i][k]){break;}
                }
            }

            if(ok){
                for(long long int k = 1; k <= 9; k++){
                    dp[i-Match[A[j]]][k]=dp[i][k];
                }
                dp[i-Match[A[j]]][A[j]]++;
                dp[i-Match[A[j]]][0]=0;
                for(long long int k = 1; k <= 9; k++){
                    dp[i-Match[A[j]]][0]+=dp[i-Match[A[j]]][k];
                }
            }
        }
    }
    for(long long int i = 9; i >= 1; i--){
        for(long long int j = 0; j < dp[0][i]; j++){
            cout<<i;
        }
    }
}    
