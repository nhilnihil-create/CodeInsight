#include <iostream>
using namespace std;
int main(void){
    // Your code here!
    int a,b,c,x;
    int count=0;
    std::cin >> a >> b >> c >> x;
    
    for (int i=0;i<=a;i++) {
        for (int j=0;j<=b;j++) {
            for (int z=0;z<=c;z++) {
                if(x == 500*i + 100*j + 50*z) {
                    count+=1;
                }
            }
        }
    }
    std::cout << count << std::endl;
    return 0;
}
