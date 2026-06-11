#include<iostream>
#include<algorithm>
#include<vector>
#include<string>
#include<utility>
#include<map>
#include<set>
#include <sstream>
#include<queue>
#include<stack>
#include<functional>
#include<math.h>
#include <iomanip>

#define A_P(n,a,d) (n/2)*(2*a + (n-1)*d)
using namespace std;


int main(void){
    int N,T;
    cin >> N;
    map<int,int> prob;
    for(int i =0; i < N; i++){
        int tmp;
        cin >> tmp;
        prob[tmp]++;
    }

    cin >> T;
    for(int i = 0; i < T; i++){
        int tmp;
        cin >> tmp;
        if(prob[tmp] > 0){
            prob[tmp]--;
        }else{
            cout << "NO" << endl;
            return 0;
        }
    }
    cout << "YES" << endl;
    return 0;
}