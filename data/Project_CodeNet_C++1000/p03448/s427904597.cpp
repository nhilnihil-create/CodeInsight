#include<iostream>
using namespace std;
int main(){
    int A,B,C,X,k = 0;
    cin >> A >> B >> C >> X;
    for (int l = 0;l <= A; l++)
    {
        for (int m = 0;m <= B; m++)
        {
            for (int n = 0;n <= C;n++)
            {
                int Y = 500*l + 100*m + 50*n;
                if(Y == X)k++;
            }
            
        }
        
    }
    cout << k << endl;
}