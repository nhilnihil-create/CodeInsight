#include <bits/stdc++.h>

#define endl '\n' ;

using namespace std;

void quick () {
    cin.tie(0);
    cout.tie(0);
    ios_base::sync_with_stdio(0);
}

int main()
{
    quick();
    int a , b ;
    cin >> a >> b ;
    bool state = false ;
    for (int i = 1 ; i <= 3 ; i++){
        if (a*b*i%2!=0)state=true;
    }
    if (state){
        cout << "Yes";
    }else {
        cout << "No";
    }
    return 0;
}
