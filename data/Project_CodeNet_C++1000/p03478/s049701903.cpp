#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<cmath>

int main () {
    int n, a, b;
    std::cin >> n >> a >> b;

    long long sum = 0;
    long long psum;
    for (int i = 1; i <= n; i++)
    {
        psum = 0;
        int tmp = i;
        if (n >= 10)
        {
            while(tmp > 0) {
                psum += tmp % 10;
                tmp /= 10;
            }
        }

        if(psum >= a && psum <= b) {
            sum += i;
        }
    }

    std::cout << sum << "\n";
}