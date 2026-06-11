    #include <iostream>
    using namespace std;
    int getsoma(int numero){
        int nax = numero;
        int somatotal = 0;
        while(numero > 0){
            nax = numero;
            nax = nax % 10;
            somatotal += nax;

            numero /= 10;
        }
        return somatotal;
    }

    int main() {
        long long int a;
        cin >> a;
        if(a == 100000 || a == 10000 || a == 1000|| a == 100 || a == 10){
            cout << 10 << endl;
            return 0;
        }
        cout << getsoma(a) <<endl;
        return 0;
    }