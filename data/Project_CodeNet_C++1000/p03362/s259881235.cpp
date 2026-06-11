#include <bits/stdc++.h>
using namespace std;

std::vector<int> Eratosthenes( const int N )
{
    std::vector<bool> is_prime( N + 1 );
    for( int i = 0; i <= N; i++ )
    {
        is_prime[ i ] = true;
    }
    std::vector<int> P;
    for( int i = 2; i <= N; i++ )
    {
        if( is_prime[ i ] )
        {
            for( int j = 2 * i; j <= N; j += i )
            {
                is_prime[ j ] = false;
            }
            P.emplace_back( i );
        }
    }
    return P;
}
int main(void) {
    int N;
    int cnt =0;    
    cin >> N;    

    // 多分55555までは求める必要無いはず
    vector<int> prime = Eratosthenes(2000);
//sort(prime.begin(), prime.end());
//for(int i=0;i<55;i++) {
//    cout << prime[i] << endl;
//}

    // 前からmodを取っていってうまく合うものだけ出す？？
    
    // 試しに素数だけ出すと？-> NG
    for(int i=0;i<prime.size();i++) {
        if(prime[i] % 5 == 1) {
            cout << prime[i] << " ";
            cnt++;
            if(cnt == N) break;
        }
    }
    cout << endl;
//printf("cnt:%d\n",cnt);

    return 0;
}
