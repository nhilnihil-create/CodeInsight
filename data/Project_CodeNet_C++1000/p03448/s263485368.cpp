#include<bits/stdc++.h>
using namespace std; //std::の省略のため
using ll = long long;

int main(){
    int a,b,c,x;

    cin >> a >> b >> c >> x;

    int sum;
    int count = 0;

    for(int i = 0; i <= a; i++){
        for(int j = 0; j <= b; j++){
            sum = 500*i + 100*j;
            if(sum > x) break;
            for(int k = 0; k <= c; k++){
                sum = 500*i + 100*j + 50*k;
                if(sum > x) {
                    break;
                }
                if(sum == x) count++;
            }
            
        }
    }

    cout << count << endl;
}