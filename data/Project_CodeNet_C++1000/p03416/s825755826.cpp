//According to all known laws of aviation, there is no way that a bee should be able to fly.
//Its wings are too small to get its fat little body off the ground. The bee, of course, flies anyway.
//Because bees don't care what humans think is impossible.
#include <bits/stdc++.h>
#define FAST_IO  ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define mod 1000000007
#define endl "\n"
using namespace std ;
using bigint = long long int ;
using vi = vector<int> ;
using vll = vector<long long int> ;
bool isPalin( int N ){
    int rev = 0 ;
    int temp = N ;
    while( N > 0 ){
        int d = N % 10 ;
        rev = rev * 10 + d ;
        N /= 10 ;
    }
    return rev == temp ;
}
int main(){
    int A , B ; cin >> A >> B ;
    int ans = 0 ;
    for( int i = A ; i <= B ; i++ ){
        if( isPalin(i) )
            ans++ ;
    }
    cout << ans << endl ;
    return 0 ;
}
