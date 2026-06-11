#include <iostream>
#include <algorithm>
#include <math.h>
#include <map>
#include <string>

using namespace std;
 
int main()
{
    int T;
    cin >> T;
    long long A, B, C, D;
    long long p, q, r;
    for(int i = 0; i<T;i++){
        cin >> A >> B >> C >> D;
        p = B;
        q = D;
        while(p%q !=0){
            r = p%q;
            p = q;
            q = r;
        }
        if(A>=B && B <=D && (B +(A%q)-q)<=C){
            cout << "Yes"<< endl;
        }else{
            cout << "No"<< endl;
        }

    }
    return 0;
}