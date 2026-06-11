#include <stdio.h>
#include <iostream>
#include <vector>

//https://atcoder.jp/contests/abc121/tasks/abc121_b

int main()
{
    std::ios::sync_with_stdio(false); // toggler av synkronisjon mellom c og c++ data streams. kan ikke blade de etter skrudd av
    std::cin.tie(NULL);               //gj;r at man ikke venter på cout og de can printe samtidig tror jeg

    //linjen er opp til 100. det er en linje p[ lengde hundre med hus p[ bare de nevte stedene]]

    int codes;
    std::cin >> codes;

    int codeSize;
    std::cin >> codeSize;

    int constant;
    std::cin >> constant;


    std::vector<int> vec(codeSize);


    for (int u = 0; u < codeSize; u++){  
        std::cin >> vec[u];
    }
 

    int validCodes = 0;
    for (int i = 0; i < codes; i++)
    {
        int result = constant;
 
        for (int u = 0; u < codeSize; u++){  
            int a;
            std::cin >> a;
            result += a * vec[u];
        }

        if (result > 0){  
            validCodes++;
        }
    }

    std::cout << validCodes << "\n";
}
