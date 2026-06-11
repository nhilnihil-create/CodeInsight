#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<set>
#include<stack>
#include<cmath>
using namespace std;
typedef long long ll;
ll mod = 1e9+7;
#define rep(i,n) for(int i = 0; i < (n); ++i)

int main(){
    int n;
    cin >> n;

    int prime_num_cnt = 0;
    int prime_prob_num = 2;

//    if ( n % 2 == 1 ) {
//        prime_prob_num = 2;
//    }
//    else {
//        prime_prob_num = 3;
//    }

    vector<int> prime_num;

    while ( 1 ) {
        if ( prime_prob_num > 55555 || prime_num_cnt == n ) {
            break;
        }
        for ( int pi = 2; pi <= prime_prob_num; ++pi ) {
            if ( pi == prime_prob_num && prime_prob_num % 5 == 1 ) {
                ++prime_num_cnt;
                prime_num.push_back(prime_prob_num);
            }
            if ( prime_prob_num % pi == 0 ) {
                break;
            }
        }
        ++prime_prob_num;
    }

    rep(i, n) {
        if ( i == n - 1 ) {
            printf("%d\n", prime_num[i] ); 
        }
        else {
            printf("%d ", prime_num[i]);
        }
    }

    return 0;
}
