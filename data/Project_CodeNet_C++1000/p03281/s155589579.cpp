#include <bits/stdc++.h>
using namespace std;
int yakusuunokazu(int N)
{
    int a = 0, p = 1;
    while (N % 2 == 0)
    {
        a++;
        N /= 2;
    }
    p *= a + 1;
    a = 0;
    while (N % 3 == 0)
    {
        a++;
        N /= 3;
    }
    p *= a + 1;
    a = 0;
    while (N % 5 == 0)
    {
        a++;
        N /= 5;
    }
    p *= a + 1;
    a = 0;
    while (N % 7 == 0)
    {
        a++;
        N /= 7;
    }
    p *= a + 1;
    a = 0;
    while (N % 11 == 0)
    {
        a++;
        N /= 11;
    }
    p *= a + 1;
    a = 0;
    while (N % 13 == 0)
    {
        a++;
        N /= 13;
    }
    p *= a + 1;
    a = 0;
    return p;
}
int main(){
    int N,i,a = 0;
    cin >> N;
    for(i = 1;i <= N;i += 2){
        if(yakusuunokazu(i) == 8){
            a++;
        }
    }
    cout << a << endl;
}