#include <bits/stdc++.h>
using namespace std;

int main() {
    int R,G,B,n;
    cin>>R>>G>>B>>n;
    int r_max=n/R;
    int G_max=n/G;


    int count=0;
    for(int i=0;i<=r_max;i++){
        for(int j=0;j<=G_max;j++){
            if((n-(R*i+G*j))>=0 && (n-(R*i+G*j))%B==0) count++;
        }
    }
    cout<<count<<endl;
}