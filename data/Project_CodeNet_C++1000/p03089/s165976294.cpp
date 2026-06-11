#include<iostream>
#include<vector>
using namespace std;

int a[105];

int main(){
    vector<int> number;
    bool salah = false;
    int N, sum = 0;
    cin >> N;
    for(int i=0; i<N; i++){
        int num;
        cin >> num;
        number.push_back(num);
        if(num > i+1) salah = true;
    }

    if(salah){
        cout << -1 << endl;
    } else {
        int count = N;
        while(count != 0){
            for(int i=count-1; i>=0; i--){
                if(number[i] == i+1){
                    number.erase(number.begin()+i);
                    a[count] = i+1; 
                    count--;
                    break;
                }
            }
        }
        for(int i=1; i<=N; i++){
            cout << a[i] << endl;
        }
    }
}