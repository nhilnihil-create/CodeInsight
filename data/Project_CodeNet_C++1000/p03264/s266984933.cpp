#include <bits/stdc++.h>
using namespace std;
int X,i,sum=0;

int main() {
    cin>>X;
    for(i=1;i<=X;i++){
        if(i%2==0){
            sum++;
        }
    }
    cout<<sum*(X-sum);
}
