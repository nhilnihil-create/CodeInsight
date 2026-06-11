#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int main(){
    int N;
    cin >> N;
    vector<long long> a(N);
    for(int i = 0; i < N; i++) cin >> a[i];
    int mina = 0, maxa = 0;
    int indmi = 0, indma = 0;
    for(int i = 0; i < N; i++){
        if(mina >= a[i]){
            mina = a[i];
            indmi = i;
        } 
        if(maxa <= a[i]){
            maxa = a[i];
            indma = i;
        }
    }
    long long temp = 0;
    int flag = 0;
    vector<int> l, r;
    if(abs(mina) > maxa){
        l.push_back(indmi + 1);
        r.push_back(indmi + 1);
        temp = mina * 2;
        a[indmi] *= 2;
        flag = 1;
    }
    else{
        l.push_back(indma + 1);
        r.push_back(indma + 1);
        temp = maxa * 2;
        a[indma] *= 2;
        flag = 2;
    }
    if(flag == 1){
        for(int i = N - 2; i >= 0; i--){
            while(a[i] > a[i + 1]){
                l.push_back(i + 1);
                r.push_back(indmi + 1);
                a[i] += temp;
                if(temp > a[i]){
                    indmi = i;
                    temp = a[i];
                }
            }
        }
    }
    else{
        for(int i = 1; i < N; i++){
            while(a[i - 1] > a[i]){
                l.push_back(i + 1);
                r.push_back(indma + 1);
                a[i] += temp;
                if(temp < a[i]){
                    indma = i;
                    temp = a[i];
                }
            }
        }
    }
    int n = (int)l.size();
    cout << n << endl;
    for(int i = 0; i < n; i++){
        cout << r[i] << ' ' << l[i] << endl;
    }
}