#include<bits/stdc++.h>

using namespace std;
int main(){
    int a,b,ans,temp;
    cin >> a >> b;
    ans = abs(a-b);
    temp= 16-(a+b);
    if(ans>temp/2) cout << ":(" << endl;
    else cout << "Yay!" << endl;
    return 0;
}