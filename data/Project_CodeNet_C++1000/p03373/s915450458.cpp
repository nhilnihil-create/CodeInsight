#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    int a,b,c,x,y;
    cin >> a >> b >> c >> x >> y;

    int min_sum = 1000000000 ; //abピザの枚数を変化させる
    for ( int i = 0 ; i <= 2*max(x,y) ; i+=2 ){
        int cnt_a = x-i/2, cnt_b = y-i/2;
      	if ( cnt_a < 0 ) cnt_a = 0;
      	if ( cnt_b < 0 ) cnt_b = 0;
        min_sum = min( min_sum, cnt_a*a + cnt_b*b + i*c);
    }
    cout << min_sum << endl;
}