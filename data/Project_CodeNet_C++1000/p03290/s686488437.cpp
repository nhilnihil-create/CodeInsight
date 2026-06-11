#include<bits/stdc++.h>
using namespace std;

const int INF=1<<30;

int main(){
    int D;
    long long G;
    cin >> D >> G;
    vector<int> p(D), c(D);
    for(int i=0; i<D; i++){
        cin >> p[i] >> c[i];
    }
    int res=INF;
    for(int bits=0; bits<(1<<D); bits++){
        bool ok=false;
        long long total=0;
        int num=0;
        for(int i=0; i<D; i++){
            if((bits>>i) & 1){
                num+=p[i];
                total+=p[i]*100*(i+1)+c[i];
            }
        }
        if(total >= G) ok=true;
        else{
            for(int i=D-1; i>=0; i--){
                if(~(bits>>i) & 1){
                    for(int j=0; j<p[i]; j++){
                        num++;
                        total+=100*(i+1);
                        if(total >= G){
                            ok=true;
                            break;
                        }
                    }
                    break;
                }
            }
        }
        if(ok) res=min(res, num);
    }
    cout << res << endl;
    return 0;
}