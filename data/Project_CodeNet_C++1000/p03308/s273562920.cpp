#include <iostream>
#include <vector>
using namespace std;

int main(){
    int min,max;
    int N,n;
    vector<int> v;
    cin >> N;
    for(int i=0;i<N;i++){
        cin >> n;
        v.push_back(n);
    }
    min=v[0];
    max=v[0];
    for(int i=0;i<N;i++){
        if(v[i]>max){
            max=v[i];
        }
        if(v[i]<min){
            min=v[i];
        }
    }
    cout << max-min;
}