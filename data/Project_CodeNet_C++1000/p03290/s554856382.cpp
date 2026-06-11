#include<iostream>
using namespace std;

int main(){
    int D, G;
    cin >> D >> G;
    int p[D], c[D];
    for(int i=0; i<D; i++){
        cin >> p[i] >> c[i];
    }

    int min_count = 1e9;
    for(int bit=0; bit<(1<<D); bit++){
        long long temp = 0;
        int high = 0;
        int count = 0;
        for(int i=0; i<D; i++){
            if(bit >> i & 1){
                temp += 100*(i+1) * p[i] + c[i];
                count += p[i];
            }else{
                high = i;
            }
        }

        int j = 0;
        while(temp<G && j<(p[high]-1)){
            temp += 100*(high+1);
            count++;
            j++;
        }

        if(temp>=G && min_count > count) min_count = count;
    }

    cout << min_count << endl;
}
