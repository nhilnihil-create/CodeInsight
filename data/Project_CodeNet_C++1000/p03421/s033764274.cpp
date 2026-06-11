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

long long int N,M,A,B,L[200200],R[202000],sum[200200]={},res=0;
long long int dp[10005]={};



vector<long long int>output;
int main()
{
    cout << fixed << setprecision(18);
    cin>>N>>A>>B;

    if(A+B<=N+1&&B>=(N+A-1)/A){
        if(A==1){
            for(long long int i = N-1; i >=0; i--){
                cout<<i+1<<" ";
            }
            cout<<endl;
            return 0;
        }
        for(long long int i = 0; i < A; i++){
            output.push_back(N-(A-1)+i);  
        }
        long long int nokori=N-A,nokoriB=B-1;
        while(nokoriB-1<=nokori-A){
            for(long long int k = 0; k < A; k++){
                output.push_back(nokori-(A-1)+k);
            }
            nokoriB--;
            nokori-=A;
        }
        long long int P=A-(nokoriB-1-(nokori-A));
        for(long long int i = nokori-P+1; i <=nokori; i++){
            output.push_back(i);
        }
        for(long long int i = nokoriB-1; i >=1 ; i-- ){
            output.push_back(i);
        }
        for(long long int i = 0; i < N; i++){
            cout<<output[i]<<" ";
        }
        cout<<endl;
    }else{
        cout<<-1<<endl;
    }
    
}
