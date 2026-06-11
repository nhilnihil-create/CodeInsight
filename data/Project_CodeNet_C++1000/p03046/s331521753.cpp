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

long long int N,M,K,s,w,res=0,A[300000]={};
//今見ている番号＋今どの段階か(なにも飛ばしていない、１つ飛ばした、２つ飛ばした)＋奇数かどうか
long long int memo[1000400]={};




int main()
{
    cout << fixed << setprecision(18);
    cin>>M>>K;
    if((1<<M)<=K||M==1&&K==1){
        cout<<-1<<endl;
        return 0;
    }else if(M==1){
        cout<<"0 0 1 1"<<endl;
        return 0;
    }else{
        long long int now=0;
        for(long long int i = 1; i < (1<<M); i++){
            if(now==K){now++;}
            
            memo[(1<<M)-1-i]=now;
            memo[(1<<M)-1+i]=now;
            now++;
        }
        memo[(1<<M)-1]=K;
        memo[(1<<(M+1))-1]=K;
    }
    for(long long int i = 0; i < (1<<(M+1)); i++){
        cout<<memo[i]<<" ";
    }
    cout<<endl;
}
