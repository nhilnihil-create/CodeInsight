#include <iostream>
using namespace std;

int numEven[100010], numOdd[100010];

int main(){
    int n, v[100010];
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> v[i];
        if(i%2==0){
            numEven[v[i]]++;
        }else{
            numOdd[v[i]]++;
        }
    }
    
    int numEvenMax = 0, numOddMax = 0;
    int numEvenMax2 = 0, numOddMax2 = 0;
    int numEvenMaxI = 0, numOddMaxI = 0;
    int numEvenMaxI2 = 0, numOddMaxI2 = 0;
    for(int i = 1; i < 100001; i++){
        if(numEvenMax < numEven[i]){
            numEvenMax2 = numEvenMax;
            numEvenMaxI2 = numEvenMaxI;
            numEvenMax = numEven[i];
            numEvenMaxI = i;
        }else if(numEvenMax2 < numEven[i]){
            numEvenMax2 = numEven[i];
            numEvenMaxI2 = i;
        }
        if(numOddMax < numOdd[i]){
            numOddMax2 = numOddMax;
            numOddMaxI2 = numOddMaxI;
            numOddMax = numOdd[i];
            numOddMaxI = i;
        }else if(numOddMax2 < numOdd[i]){
            numOddMax2 = numOdd[i];
            numOddMaxI2 = i;
        }
    }
    
    int ret;
    if(numEvenMaxI != numOddMaxI){
        ret = n/2 - numEvenMax + n/2 - numOddMax;
        // cout << n/2 - numEvenMax <<','<< n/2 - numOddMax;
    }else{
        int ret1 = n/2 - numEvenMax + n/2 - numOddMax2;
        int ret2 = n/2 - numEvenMax2 + n/2 - numOddMax;
        // cout << n/2 - numEvenMax <<','<< n/2 - numOddMax << endl;
        // cout << numEvenMax << "," << numOddMax << endl;
        // cout << numEvenMax2 << "," << numOddMax2 << endl;
        ret = min(ret1, ret2);
    }
    
    cout << ret << '\n';
    
    
    return 0;
}