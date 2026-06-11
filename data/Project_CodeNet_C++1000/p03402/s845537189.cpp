#include <bits/stdc++.h>

int main(){
    int A, B;
    std::cin >> A >> B;
    
    std::cout << 100 << " " << 100 << std::endl;
    
    std::vector< std::string > out(100);
    for(int i=0; i<50; i++){
        std::string out_1line(100, '.');
        if(i % 2 == 0){
            int index = 0;
            while(B != 1 && index != 100){
                out_1line[index] = '#';
                index += 2;
                B--;
            }
        }
        out[i] = out_1line;
    }
    
    for(int i=0; i<50; i++){
        std::string out_1line(100, '#');
        if(i % 2 == 0){
            int index = 0;
            while(A != 1 && index != 100){
                out_1line[index] = '.';
                index += 2;
                A--;
            }
        }
        out[99 - i] = out_1line;
    }
    
    for(int i=0; i<100; i++){
        std::cout << out[i] << std::endl;
    }
    
    
    return 0;
    
}
