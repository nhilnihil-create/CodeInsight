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

int main(){
    char ch[4][4] ;
    for( int i = 0 ; i < 3 ; i++ )
        for( int j = 0 ; j < 3 ; j++ )
            cin >> ch[i][j] ;
    
    cout << ch[0][0] << ch[1][1] << ch[2][2] << endl ;
    return 0 ;
}
