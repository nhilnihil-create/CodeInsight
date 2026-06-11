#include <bits/stdc++.h>
using namespace std;

int main(){
    int n = 0, d = 0, x;
    cin>>n;
    cin>>d>>x;
    int temp = 0, cont = 0;
    for(int i = 0; i < n; i++){
        cin>>temp;
        cont+= ceil((float)d/temp);
    }
    cout<<cont+x;

    return 0;
}