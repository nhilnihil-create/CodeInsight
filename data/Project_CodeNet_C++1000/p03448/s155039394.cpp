#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<string>
#include<iomanip>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;

int a, b, c, x;
int res = 0;

int main(){
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> x;

    for(int c500=0;c500 < a+1;c500++){
        for(int c100=0;c100<b+1;c100++){
            for(int c50=0;c50<c+1;c50++){
                if(500*c500 + 100*c100 + 50*c50 == x) res++;
            }
        }
    }

    cout << res << endl;
}   