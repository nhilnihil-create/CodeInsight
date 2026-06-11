#include <iostream> 
#include <stdlib.h> 
#include <string.h> 
#include <string> 
#include <sstream>
#include <cstring> 
#include<cmath>
using namespace std;
int main()
{
    int x, z = 0;
    int y[101];
    cin >> x;

    for (int i = 0; i < x; i++) {
        cin >> y[i];
        if (i > 0) {
            int c = 0;
            for (int j = i-1; j >=0; j--) {
                
                if (y[i] == y[j] && c == 0) {
                    z++;
                    c = 1;
                }
            }
        }
    }
   
        cout << x - z;
    
    return 0;
}