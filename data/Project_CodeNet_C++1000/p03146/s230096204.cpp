#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;


int main(){
ll N;
cin >> N;
ll num[1000000];
num[0] = N;
ll i = 1;
while(true){

if(N%2==0){
N/=2;
}
else N=N*3+1;

num[i] = N;

for(ll j = 0; j < i; j++){
    if(num[i] == num[j]){
        cout << i+1 << endl;
        return 0;
    }
}
i++;

}
}