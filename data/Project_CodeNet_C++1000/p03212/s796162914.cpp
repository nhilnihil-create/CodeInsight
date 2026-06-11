#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);++i)
using ll = long long;
using pii = pair<int, int>;
using vi = vector<int>;
using vii = vector<vector<int>>;

int main(){
    long long N;
    cin >> N;
    queue<long long> q;
    q.push(0);
    int count = 0;
    while( !q.empty() ){
        long long t = q.front(); q.pop();
        if ( t > N ) continue;
        long long t_tmp = t;
        bool b3 = false;
        bool b5 = false;
        bool b7 = false;
        while( t_tmp > 0 ){
            switch ( t_tmp % 10 )
            {
            case 3:
                b3 = true;
                break;
            case 5:
                b5 = true;
                break;
            case 7:
                b7 = true;
                break;
            default:
                break;
            }
            t_tmp = t_tmp / 10;
        }
        if ( b3 && b5 && b7 ) ++count;
        q.push( 10*t + 3 );
        q.push( 10*t + 5 ); 
        q.push( 10*t + 7 );
    }
    cout << count;
}