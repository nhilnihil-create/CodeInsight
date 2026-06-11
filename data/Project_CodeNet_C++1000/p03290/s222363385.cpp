#include <iostream>
#include <vector>
using namespace std;
int main(void){
    int d,g,i,j,k;
    long long ans = 100000000;
    cin >> d >> g;
    vector<int> p(d);
    vector<int> c(d);
    for(i=0;i<d;i++) cin >> p[i] >> c[i];
    for(i=0;i<(1<<d);i++){
        long long tmp=0;
        int cnt = 0;
        for(j=0;j<d;j++){
            if(i&(1<<j)){
                tmp = tmp + 100*(j+1)*p[j]+c[j];
                cnt += p[j];
            }
        }
        if(tmp>=g){
            if(cnt<ans) ans = cnt;
        }
        else{
            for(j=d-1;j>=0;j--){
                if(i&(1<<j)) continue;
                else{
                    for(k=0;k<p[j];k++){
                        if(tmp>=g) break;
                        tmp = tmp + 100*(j+1);
                        cnt++;
                    }
                }
            }
            if(cnt<ans) ans = cnt;
        }
    }
    cout << ans;
}