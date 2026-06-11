#include <iostream>//cout<<right で右揃え
#include <iomanip>//cout<<setw(数字) で空白による桁揃え
#include <string>
#include <vector>
#include <queue>
#include <deque>
#include <algorithm>
#include <cstdlib>//abs()で整数絶対値
#include <cmath>//abs()かfabs()で少数絶対値
#include <functional>//sort第三引数greater<型名>()で降順
#include <map>

using namespace std;
using ll = long long int;

int main(){
    int N,K;cin>>N>>K;
    vector<int> V(N);
    for(int i=0;i<N;i++){
        cin >> V[i];
    }
    int max = 0;
    int sum = 0;
    vector<int> minus;
    for(int i=0;i<=min(N,K);i++){
        for(int j=0;j<=min(N-i,K-i);j++){
            sum = 0;
            minus.clear();
            for(int k=0;k<i;k++){
                sum += V[k];
                if(V[k]<0){
                    minus.push_back(V[k]);
                }
            }
            for(int k=0;k<j;k++){
                sum += V[(N-1)-k];
                if(V[(N-1)-k]<0){
                    minus.push_back(V[(N-1)-k]);
                }
            }
            sort(minus.begin(),minus.end(),greater<int>());
            if(minus.size()>0){
                for(int k=0;k<K-(i+j)&&minus.size()!=0;k++){
                    sum -= minus.back();
                    minus.pop_back();
                }
            }
            if(max<sum) max = sum;
        }
    }
    cout << max << endl;
}