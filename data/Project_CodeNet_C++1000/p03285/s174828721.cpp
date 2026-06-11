#include <iostream>
#include <stdio.h>
#include <vector> 
#include <math.h> 
using namespace std;
int main(void){
    int N; cin >> N;
    int i = 0;
    int j = 0;
    string answer = "No";
    while(i < 26) {
        j = 0;
        while (j < 15) {
            int tmp = i * 4 + 7 * j;
            if (tmp == N) {
                answer = "Yes";
            }
            j++;
        }
        i++;
    }
    cout << answer << endl;
}