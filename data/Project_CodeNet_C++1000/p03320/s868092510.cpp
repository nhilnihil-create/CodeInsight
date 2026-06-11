#include<bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;
const int mod = 1e9 + 7;
typedef long long ll;
#define mp make_pair

ll p[22],n,i,x,y,t,z,zz;

int main(){
    cin >> n;
    for(i=p[0]=1;i<=15;i++) p[i] = p[i-1] * 10;
    x = 1;
    for(; n-- ;){
        cout << x << endl;
        y = ++x;

        t = 0;
        for(z=y; z ; z/=10) t += z % 10;
        z = y;
        zz = t;

        for(i=0 ;i<15; ){
            if(y / p[i] % 10 == 9) { i++; continue; }
            y += p[i]; t++;
            if(z * t > zz * y)
                z = y, zz = t;
        }
        
        x = z;
    }
    
    
    return 0;

}