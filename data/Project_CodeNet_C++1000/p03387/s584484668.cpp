#include <bits/stdc++.h>

using namespace std;

int main(){
    int a, b, c;
    cin >> a >> b >> c;
    
    if (a > b) swap(a,b);
    if (b > c) swap(b,c);
    
    // a <= b <= c
    
    int count = 0;
    
    if ((c-b)% 2 == 0 && (c-a)%2 == 0){
        count += (c-b)/2 + (c-a)/2;
    }
    else if ((c-b)%2 == 1 && (c-a)%2 == 1){
         count += (c-b)/2 + (c-a)/2 + 1;
    }
    else {
       count += (c-b)/2 + (c-a)/2 + 2;
    }
    
    cout << count << endl;
}