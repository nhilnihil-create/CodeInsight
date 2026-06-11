#include<bits/stdc++.h>
using namespace std;

int main(){
    int n,A,B,a=0,b=0,c=0,rta;
    cin >> n >> A >> B;
    int x[n];
    for(int i=0;i<n;i++){
        cin >> x[i];
    }
    for(int i=0;i<n;i++){
        if(x[i]<=A)a++;
        else if(x[i]>B)c++;
        else b++;
    }
    rta=min({a,b,c});
    cout << rta << endl;
    return 0;
}
