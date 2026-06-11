#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    int k,score;
    cin >> n >> k;
    double ans=0;
    for(int i=1;i<=n;i++){
        score = i;
        double temp=(double)1/(double)n;
        while(true){
            if(score>=k){
                ans += temp;
                break;
            }else{
                temp *= 0.5;
                //cout << temp << endl;
                score *= 2;
            }
        }
    }
    printf("%.12f\n", ans);
}