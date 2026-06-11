#include <iostream>
#include <vector>
#define bitmax 20
using std::cin;
using std::cout;
int l;
int main()
{
    std::ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin >> l;
    cout << bitmax << ' ';
    int ans = 36;
    if((l >> (bitmax - 1)) & 1)
      ans += 2;
    for(int i = (bitmax - 2); i >= 0; --i)
      if((l >> i) & 1) ++ ans;
    cout << ans << '\n';


    for(int i = bitmax - 1, j = 1; i > 1; --i, j <<= 1){
      cout << i << ' ' << (i + 1) << ' ' << j << '\n';
      cout << i << ' ' << (i + 1) << ' ' << 0 << '\n';
    }
    int j = 0;
    if((l >> (bitmax - 1)) & 1){
      cout << "1 2 0\n1 2 " << (1 << (bitmax - 2)) << '\n';
      j |= 1 << (bitmax - 1);
    }
    for(int i = (bitmax - 2); i >= 0; --i)
      if((l >> i) & 1){
        cout << 1 << ' ' << (bitmax - i) << ' ' << j << '\n';
        j |= 1 << i;
      }
    return 0;
}
