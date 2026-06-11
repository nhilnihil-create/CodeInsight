#include <bits/stdc++.h>

using namespace std;

int main(){
    int N;
    long long Y;
    cin >> N;
    cin >> Y;

    int a=-1,b = -1,d= -1;

    for(int i = 0;i <= N;i++)
        for(int j = 0;j <= N;j++){
            int c = N - j -i;
            int total = 10000*i+5000*j+1000*c;
            if(i + j +c == N && Y == total && c >= 0){
                a = i;
                b = j;
                d = c;
                break;
            }
        }

    cout << a << " " << b << " " << d << endl;
    
    
    


}