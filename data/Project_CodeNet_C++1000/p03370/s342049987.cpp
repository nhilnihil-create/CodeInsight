#include <bits/stdc++.h>

using namespace std;

int main()
{

    int n,x;
    cin >> n >> x;
    vector<int>po(n);
    int soma=0,menor=0;
    for(int i=0;i<n;i++){
        cin >> po[i];
        soma+=po[i];
        if( po[i]<menor || i==0){
            menor = po[i];
        }
    }
    if(x-soma > menor){
        n+=(x-soma)/menor;
    }
    cout << n << endl;

    return 0;
}