#include <bits/stdc++.h>
using namespace std;

int main(void)
{
    int A, B, C, X;
    cin >> A >> B >> C >> X;

    int a,b,c;;
    int count = 0;
    for( a = 0; a <= A; a++){
        for(b=0;b<=B;b++){
            for(c=0;c<=C;c++){
                if(500*a + 100*b + 50*c == X) count++;
            }
        }
    }
    
    cout << count << endl;

}