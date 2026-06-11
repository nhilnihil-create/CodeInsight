#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
using namespace std;

int main() {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    bool kanou = false;

    int CA = max(c-a,a-c);
    int BA = max(b-a,a-b);
    int CB = max(c-b,b-c);

    if(CA<=d){
        kanou = true;
    }
    if(BA<=d && CB<=d){
        kanou = true;
    }

    if(kanou){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl; 
    }
}
